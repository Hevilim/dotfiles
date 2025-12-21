from fastapi import Request, HTTPException

from app.config import settings
from aiogram.utils.web_app import WebAppInitData, safe_parse_webapp_init_data

from authx import AuthX, AuthXConfig  # RequestToken

config = AuthXConfig(
    JWT_ALGORITHM = "HS256",
    JWT_SECRET_KEY = "SECRET_KEY",
    JWT_TOKEN_LOCATION = ["headers"],
)

authx = AuthX(config=config)


def auth(request: Request) -> WebAppInitData:
    try:
        auth_string = request.headers.get("initData", None)

        if auth_string:
            data = safe_parse_webapp_init_data(
                settings.BOT_TOKEN.get_secret_value(), 
                auth_string)
            
            return data
        print(1)
        raise HTTPException(401, {"error": "Unauthorized"})
    except Exception:
        raise HTTPException(401, {"error": "Unauthorized"})
    