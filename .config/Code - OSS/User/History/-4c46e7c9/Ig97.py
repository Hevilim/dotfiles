from fastapi import APIRouter
from pydantic import BaseModel, EmailStr
from fastapi.responses import JSONResponse

from app.db.crud import add_user

router = APIRouter()


class UserSignupSchema(BaseModel):
    tg_id: int
    first_name: str
    # last_name: str
    # email: EmailStr


@router.post("/signup")
async def signup(data: UserSignupSchema):
    await add_user(data)
    return JSONResponse(
        status_code=200,
        content={"message": "User registered successfully"}
    )