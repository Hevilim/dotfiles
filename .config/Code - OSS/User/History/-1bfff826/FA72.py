from fastapi import APIRouter

router = APIRouter()


@router.get("/quiz")
async def quiz():
    