# Generated by Django 5.0.6 on 2024-07-29 10:22

import shortuuid.main
from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('pong', '0070_remove_party_draw_user_one_and_more'),
    ]

    operations = [
        migrations.AlterField(
            model_name='chat',
            name='name',
            field=models.CharField(default=shortuuid.main.ShortUUID.uuid, max_length=255, unique=True),
        ),
    ]
