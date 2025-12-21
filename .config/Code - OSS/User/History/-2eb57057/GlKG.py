from django.urls import path

urlpatterns = [
    path('', views.home.index, name='index'),
]