from fastapi import APIRouter, HTTPException
from pydantic import BaseModel, EmailStr
from fastapi.responses import JSONResponse

from app.db.crud import get_user, add_user

router = APIRouter()


class UserSignupSchema(BaseModel):
    tg_id: int
    first_name: str
    last_name: str
    # email: EmailStr


@router.post("/signup")
async def signup(user_data: UserSignupSchema):
    user = await get_user(user_data.tg_id)
    if user:
        raise HTTPException(
            status_code=409,
            content="User already exists"
        )
    
    await add_user(user_data)
    return JSONResponse(
        status_code=200,
        content={"message": "User registered successfully"}
    )