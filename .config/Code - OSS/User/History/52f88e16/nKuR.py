from fastapi import APIRouter, Depends, HTTPException
from fastapi.responses import JSONResponse

from aiogram.utils.web_app import WebAppInitData

from app.db.crud import get_user
from app.api.deps import auth, authx

router = APIRouter()


@router.get("/login")
async def login(auth_data: WebAppInitData = Depends(auth)) -> JSONResponse:
    user = await get_user(auth_data.user.id)
    if user:
        return JSONResponse(status_code=200, content={"message": "OK"})
        # token = authx.create_access_token(uid=str(user.tg_id))
        # return {"access_token": token}
    raise HTTPException(401, {"error": "Unauthorized"})
