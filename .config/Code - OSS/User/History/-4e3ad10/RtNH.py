from app.db.models.user import User
from app.db.models.subject import Subject, Question, Answer
from sqlalchemy.future import select
from sqlalchemy import func
from app.db.core import async_session

from fastapi import HTTPException


async def add_user(data):
    async with async_session() as session:
        new_user = User(tg_id=data.tg_id, 
                        first_name= data.first_name,
                        last_name=data.last_name,
                        email=data.email)
        
        session.add(new_user)
        await session.commit()
        await session.refresh(new_user)


async def get_user(user_id) -> User:
    async with async_session() as session:
        result = await session.execute(select(User).where(User.tg_id == user_id))
        if result:
            return result.scalars().first()
        raise HTTPException(401, {"error": "Unauthorized"})


async def get_questions(subject_id) -> Question:
    async with async_session() as session:
        result = await session.execute(select(Question).where(Subject.id == subject_id).
        options(selectinload(Question.answers)
            )
        )
        questions = result.scalars().all()
        if questions:
            return questions
        raise HTTPException(404, {"error": "Subject not found"})
