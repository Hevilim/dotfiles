from fastapi import APIRouter



from app.db.crud import get_questions

router = APIRouter()


@router.get("/quiz")
async def quiz():
    