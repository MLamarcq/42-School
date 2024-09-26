# Generated by Django 5.0.6 on 2024-07-26 11:39

import django.db.models.deletion
import shortuuid.main
from django.conf import settings
from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('pong', '0055_alter_chat_name'),
    ]

    operations = [
        migrations.AddField(
            model_name='newuser',
            name='in_waiting_pong',
            field=models.BooleanField(default=False),
        ),
        migrations.AddField(
            model_name='newuser',
            name='in_waiting_tic',
            field=models.BooleanField(default=False),
        ),
        migrations.AddField(
            model_name='party',
            name='is_ended',
            field=models.BooleanField(default=False),
        ),
        migrations.AddField(
            model_name='party',
            name='score_blue',
            field=models.IntegerField(default=0),
        ),
        migrations.AddField(
            model_name='party',
            name='score_red',
            field=models.IntegerField(default=0),
        ),
        migrations.AddField(
            model_name='party',
            name='user_blue',
            field=models.ForeignKey(default=1, on_delete=django.db.models.deletion.CASCADE, related_name='user_blue', to=settings.AUTH_USER_MODEL),
        ),
        migrations.AddField(
            model_name='party',
            name='user_red',
            field=models.ForeignKey(default=1, on_delete=django.db.models.deletion.CASCADE, related_name='user_red', to=settings.AUTH_USER_MODEL),
        ),
        migrations.AddField(
            model_name='tournament',
            name='alias1',
            field=models.CharField(default=0, max_length=15),
        ),
        migrations.AddField(
            model_name='tournament',
            name='alias2',
            field=models.CharField(default=0, max_length=15),
        ),
        migrations.AddField(
            model_name='tournament',
            name='alias3',
            field=models.CharField(default=0, max_length=15),
        ),
        migrations.AddField(
            model_name='tournament',
            name='alias4',
            field=models.CharField(default=0, max_length=15),
        ),
        migrations.AddField(
            model_name='tournament',
            name='party1',
            field=models.OneToOneField(blank=True, null=True, on_delete=django.db.models.deletion.CASCADE, related_name='tournament1', to='pong.party'),
        ),
        migrations.AddField(
            model_name='tournament',
            name='party2',
            field=models.OneToOneField(blank=True, null=True, on_delete=django.db.models.deletion.CASCADE, related_name='tournament2', to='pong.party'),
        ),
        migrations.AddField(
            model_name='tournament',
            name='party3',
            field=models.OneToOneField(blank=True, null=True, on_delete=django.db.models.deletion.CASCADE, related_name='tournament3', to='pong.party'),
        ),
        migrations.AlterField(
            model_name='chat',
            name='name',
            field=models.CharField(default=shortuuid.main.ShortUUID.uuid, max_length=255, unique=True),
        ),
        migrations.AlterField(
            model_name='party',
            name='loser',
            field=models.ForeignKey(blank=True, default=0, null=True, on_delete=django.db.models.deletion.CASCADE, related_name='lost_parties', to=settings.AUTH_USER_MODEL),
        ),
        migrations.AlterField(
            model_name='party',
            name='winner',
            field=models.ForeignKey(blank=True, default=0, null=True, on_delete=django.db.models.deletion.CASCADE, related_name='won_parties', to=settings.AUTH_USER_MODEL),
        ),
        migrations.AlterField(
            model_name='tournament',
            name='participant2',
            field=models.ForeignKey(blank=True, null=True, on_delete=django.db.models.deletion.CASCADE, related_name='participated_tournaments2', to=settings.AUTH_USER_MODEL),
        ),
        migrations.AlterField(
            model_name='tournament',
            name='participant3',
            field=models.ForeignKey(blank=True, null=True, on_delete=django.db.models.deletion.CASCADE, related_name='participated_tournaments3', to=settings.AUTH_USER_MODEL),
        ),
        migrations.AlterField(
            model_name='tournament',
            name='participant4',
            field=models.ForeignKey(blank=True, null=True, on_delete=django.db.models.deletion.CASCADE, related_name='participated_tournaments4', to=settings.AUTH_USER_MODEL),
        ),
        migrations.AlterField(
            model_name='tournament',
            name='winner',
            field=models.ForeignKey(blank=True, null=True, on_delete=django.db.models.deletion.CASCADE, related_name='won_tournaments', to=settings.AUTH_USER_MODEL),
        ),
        migrations.CreateModel(
            name='Invitation',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('is_accepted', models.BooleanField(default=False)),
                ('is_ended', models.BooleanField(default=False)),
                ('receiver', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, related_name='receive_invitation', to=settings.AUTH_USER_MODEL)),
                ('sender', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, related_name='send_invitation', to=settings.AUTH_USER_MODEL)),
            ],
        ),
    ]