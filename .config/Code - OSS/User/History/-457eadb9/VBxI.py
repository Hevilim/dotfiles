from app.db.core import Base
from sqlalchemy import ForeignKey, Integer
from sqlalchemy.dialects.postgresql import ARRAY
from sqlalchemy.orm import Mapped, mapped_column, relationship