#!/bin/bash

# Получаем список клиентов
clients=$(hyprctl clients -j)

# Получаем список workspaces
workspaces=$(hyprctl workspaces -j | jq -r '.[].id' | sort -n)

output="["

for ws_id in $workspaces; do
    # Получить все окна на этом workspace
    titles=$(echo "$clients" | jq -r --arg ws "$ws_id" '
        .[] | select(.workspace.id == ($ws | tonumber)) | .initialClass or .class or .title
    ')
    
    label="$ws_id"
    for title in $titles; do
        label="$label $title"
    done

    output="$output{\"text\": \"$label\"},"
done

# Удалить последнюю запятую и завершить JSON-массив
output="${output%,}]"

echo "$output"
