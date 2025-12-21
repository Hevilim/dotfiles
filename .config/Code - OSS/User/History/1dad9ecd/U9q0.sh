#!/bin/bash

clients=$(hyprctl clients -j)
workspaces=$(hyprctl workspaces -j | jq -r '.[].id' | sort -n)

# Начинаем JSON-массив
echo "["

first=1
for ws_id in $workspaces; do
    titles=$(echo "$clients" | jq -r --arg ws "$ws_id" '
        .[] | select(.workspace.id == ($ws | tonumber)) | .initialClass // .class // .title
    ')

    label="$ws_id"
    for title in $titles; do
        label="$label $title"
    done

    # Печатаем объект JSON
    if [ $first -eq 0 ]; then
        echo ","
    fi
    echo -n "{\"text\": \"$label\", \"tooltip\": \"Workspace $ws_id\"}"
    first=0
done

echo "]"
