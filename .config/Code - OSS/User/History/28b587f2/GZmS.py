#!/usr/bin/env python3
import json
import subprocess

# Иконки по class/window name
icon_map = {
    "foot": "",
    "Alacritty": "",
    "kitty": "",
    "gnome-terminal": "",
    "firefox": "",
    "code": "",
    "code-oss": "",
    "Spotify": "",
    "discord": "",
    "thunar": "",
    "nemo": "",
    "steam": "",
}

def get_windows():
    try:
        result = subprocess.run(["hyprctl", "clients", "-j"], stdout=subprocess.PIPE, check=True)
        clients = json.loads(result.stdout)
        return clients
    except Exception as e:
        return []

def get_workspaces(clients):
    workspaces = {}
    for client in clients:
        ws = str(client.get("workspace", {}).get("id"))
        app = client.get("class")
        if ws not in workspaces:
            workspaces[ws] = []
        icon = icon_map.get(app, "")  #  — default window icon
        if icon not in workspaces[ws]:
            workspaces[ws].append(icon)
    return workspaces

def format_output(workspaces):
    result = []
    for ws in sorted(workspaces.keys(), key=lambda x: int(x)):
        icons = " ".join(workspaces[ws])
        result.append(f"{ws}: {icons}")
    return " | ".join(result)

clients = get_windows()
workspaces = get_workspaces(clients)
output = {
    "text": format_output(workspaces),
    "tooltip": "Запущенные приложения по рабочим столам",
    "class": "workspaces-icons"
}
print(json.dumps(output))
