from app.db.core import Base
from sqlalchemy import String
from sqlalchemy.dialects.postgresql import ARRAY
from sqlalchemy.orm import Mapped, mapped_column


class Question(Base):
    __tablename__ = "questions"

    id: Mapped[int] = mapped_column(primary_key=True, index=True)
    question_text: Mapped[str] = mapped_column()


class SubjectQuestions(Base):
    pass


class Answer(Base): 
    __tablename__ = "answers"

    id: Mapped[int] = mapped_column(primary_key=True, index=True)
    answer_text: Mapped[str] = mapped_column()
    is_correct: Mapped[bool] = mapped_column(default=False)


class Quiz(Base):
    __tablename__ = "quiz"

    id: Mapped[int] = mapped_column(primary_key=True, index=True)
    questions: Mapped[list[int]] = mapped_column(ARRAY(Integer))
