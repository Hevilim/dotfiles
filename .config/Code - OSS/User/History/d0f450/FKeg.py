from app.db.core import Base 
from sqlalchemy import BigInteger
from sqlalchemy.orm import Mapped, mapped_column

 
class User(Base):
    __tablename__ = "users"

    id: Mapped[int] = mapped_column(primary_key=True, index=True)
    tg_id: Mapped[int] = mapped_column(BigInteger)
    first_name: Mapped[str] = mapped_column()
    last_name: Mapped[str] = mapped_column()
    email: Mapped[str] = mapped_column()


class Student(Base):
    pass


class Teacher(Base):
    pass


class Admin(Base):
    pass 