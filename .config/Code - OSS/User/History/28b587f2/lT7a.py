#!/usr/bin/env python3
import json
import subprocess

icon_map = {
    "foot": " ",
    "Alacritty": " ",
    "kitty": " ",
    "gnome-terminal": " ",
    "firefox": " ",
    "code": " ",
    "code-oss": " ",
    "Spotify": " ",
    "discord": " ",
    "thunar": " ",
    "nemo": " ",
    "steam": " ",
}

def get_clients():
    try:
        return json.loads(subprocess.check_output(["hyprctl", "clients", "-j"]))
    except:
        return []

def get_active_workspace():
    try:
        ws = json.loads(subprocess.check_output(["hyprctl", "activeworkspace", "-j"]))
        return str(ws.get("id"))
    except:
        return None

def get_workspaces(clients):
    workspaces = {}
    for client in clients:
        ws = str(client.get("workspace", {}).get("id"))
        app = client.get("class")
        if ws not in workspaces:
            workspaces[ws] = []
        icon = icon_map.get(app, "")
        if icon not in workspaces[ws]:
            workspaces[ws].append(icon)
    return workspaces

def format_output(workspaces, active_ws):
    output_list = []
    actions = {}

    for idx, ws in enumerate(sorted(workspaces.keys(), key=lambda x: int(x))):
        icons = " ".join(workspaces[ws])
        label = f"[{ws}: {icons}]" if ws == active_ws else f"{ws}: {icons}"
        output_list.append(label)

        # Добавим action по индексу
        actions[str(idx)] = {
            "command": f"hyprctl dispatch workspace {ws}"
        }

    return " | ".join(output_list), actions

clients = get_clients()
workspaces = get_workspaces(clients)
active_ws = get_active_workspace()

text, actions = format_output(workspaces, active_ws)

output = {
    "text": text,
    "tooltip": "Рабочие столы и приложения",
    "class": "workspaces-icons",
    "actions": actions
}

print(json.dumps(output))