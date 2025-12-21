from app.db.core import Base

from sqlalchemy import String
from sqlalchemy.orm import Mapped, mapped_column


class Question(Base):
    __tablename__ = "questions"

    id: Mapped[int] = mapped_column(primary_key=True, index=True)
    question_text: Mapped[str] = mapped_column()

    subject_id: Mapped[int] = mapped_column(ForeignKey("subjects.id"))

    subject: Mapped["Subject"] = relationship(back_populates="questions")

    answers: Mapped[list["Answer"]] = relationship(back_populates="question")
