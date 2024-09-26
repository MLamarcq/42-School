# Generated by Django 5.0.6 on 2024-07-15 21:38

import shortuuid.main
from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('pong', '0008_alter_chat_name'),
    ]

    operations = [
        migrations.AlterField(
            model_name='chat',
            name='name',
            field=models.CharField(default=shortuuid.main.ShortUUID.uuid, max_length=255, unique=True),
        ),
    ]
