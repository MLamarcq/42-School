"""
Django settings for mysite project.

Generated by 'django-admin startproject' using Django 5.0.6.

For more information on this file, see
https://docs.djangoproject.com/en/5.0/topics/settings/

For the full list of settings and their values, see
https://docs.djangoproject.com/en/5.0/ref/settings/
"""

from pathlib import Path
from dotenv import load_dotenv
import environ
import os


# Build paths inside the project like this: BASE_DIR / 'subdir'.
BASE_DIR = Path(__file__).resolve().parent.parent

print("BASE_DIR 1 = ", BASE_DIR)

# Quick-start development settings - unsuitable for production
# See https://docs.djangoproject.com/en/5.0/howto/deployment/checklist/

# SECURITY WARNING: keep the secret key used in production secret!
SECRET_KEY = 'django-insecure-42+i!wjl(0_x1aof&wtv*u4h!2epyy_&%#dt8js%tgxz%2vk)3'

# SECURITY WARNING: don't run with debug turned on in production!
DEBUG = True

ALLOWED_HOSTS = ['localhost', '127.0.0.1', 'pong.fr']

AUTH_USER_MODEL = "pong.NewUser"

# Application definition

INSTALLED_APPS = [
	'daphne',
	'django.contrib.admin',
	'django.contrib.auth',
	'django.contrib.contenttypes',
	'django.contrib.sessions',
	'django.contrib.messages',
	'django.contrib.staticfiles',
	'pong.apps.PongConfig',
	#'django_otp',
    #'django_otp.plugins.otp_totp',
	#'django_otp',
    #'django_otp.plugins.otp_static',
    #'django_otp.plugins.otp_totp',
    #'django_otp.plugins.otp_email',  # <- if you want email capability.
    #'two_factor',
    #'two_factor.plugins.phonenumber',  # <- if you want phone number capability.
    #'two_factor.plugins.email',  # <- if you want email capabili
]

MIDDLEWARE = [
	'django.middleware.security.SecurityMiddleware',
	'django.contrib.sessions.middleware.SessionMiddleware',
	'django.middleware.common.CommonMiddleware',
	'django.middleware.csrf.CsrfViewMiddleware',
	'django.contrib.auth.middleware.AuthenticationMiddleware',
	'django.contrib.auth.middleware.AuthenticationMiddleware',
    #'django_otp.middleware.OTPMiddleware',
	'django.contrib.messages.middleware.MessageMiddleware',
	'django.middleware.clickjacking.XFrameOptionsMiddleware',
]

ROOT_URLCONF = 'mysite.urls'

TEMPLATES = [
	{
		'BACKEND': 'django.template.backends.django.DjangoTemplates',
		'DIRS': [BASE_DIR / "pong/templates/pong"],
		'APP_DIRS': True,
		'OPTIONS': {
			'context_processors': [
				'django.template.context_processors.debug',
				'django.template.context_processors.request',
				'django.contrib.auth.context_processors.auth',
				'django.contrib.messages.context_processors.messages',
			],
		},
	},
]

# WSGI_APPLICATION = 'mysite.wsgi.application'

ASGI_APPLICATION = "pong.asgi.application"


# Database
# https://docs.djangoproject.com/en/5.0/ref/settings/#databases

env_path = Path('/home/sgoinfre/PONG/.env')


# Charger les variables d'environnement à partir du fichier .env
load_dotenv(env_path)


DATABASES = {
	'default': {
		'ENGINE': 'django.db.backends.postgresql',
		'NAME': os.getenv('DB_NAME'),
		'USER': os.getenv('DB_USER'),
		'PASSWORD': os.getenv('DB_PASSWORD'),
		'HOST': os.getenv('DB_HOST'),
		'PORT': '5432'
	}
}



# SECRET_KEY = os.getenv('SECRET_KEY', 'my-default-secret-key')
# DEBUG = os.getenv('DEBUG', 'False').lower() in ['true', '1']
# ALLOWED_HOSTS = os.getenv('ALLOWED_HOSTS', '').split(',')


# Password validation
# https://docs.djangoproject.com/en/5.0/ref/settings/#auth-password-validators`
AUTH_PASSWORD_VALIDATORS = [
	{
		'NAME': 'django.contrib.auth.password_validation.UserAttributeSimilarityValidator',
	},
	{
		'NAME': 'django.contrib.auth.password_validation.MinimumLengthValidator',
	},
	{
		'NAME': 'django.contrib.auth.password_validation.CommonPasswordValidator',
	},
	{
		'NAME': 'django.contrib.auth.password_validation.NumericPasswordValidator',
	},
]


# Internationalization
# https://docs.djangoproject.com/en/5.0/topics/i18n/

LANGUAGE_CODE = 'en-us'

TIME_ZONE = 'UTC'

USE_I18N = True

USE_TZ = True


# Static files (CSS, JavaScript, Images)
# https://docs.djangoproject.com/en/5.0/howto/static-files/

STATIC_URL = 'static/'

STATICFILES_DIRS = [
	 os.path.join(BASE_DIR, 'pong/static'),
]

print("BASE_dIR =", BASE_DIR)

print("Statifile dir =", STATICFILES_DIRS)

# STATIC_ROOT = BASE_DIR / "staticfiles"

# Default primary key field type
# https://docs.djangoproject.com/en/5.0/ref/settings/#default-auto-field

DEFAULT_AUTO_FIELD = 'django.db.models.BigAutoField'
MEDIA_URL = '/media/'
MEDIA_ROOT = os.path.join(BASE_DIR, 'media')


CSRF_TRUSTED_ORIGINS = [
    'https://localhost:9443',
    'https://127.0.0.1:9443',
    'https://pong.fr'
]


SECURE_PROXY_SSL_HEADER = ('HTTP_X_FORWARDED_PROTO', 'https')
SECURE_SSL_REDIRECT = True
SESSION_COOKIE_SECURE = True
CSRF_COOKIE_SECURE = True
SECURE_HSTS_SECONDS = 3600
SECURE_HSTS_INCLUDE_SUBDOMAINS = True
SECURE_HSTS_PRELOAD = True

LOGGING = {
   'version': 1,
   'disable_existing_loggers': False,
   'formatters': {
       'verbose': {
           'format': '{levelname} {asctime} {module} {message}',
           'style': '{',
       },
       'simple': {
           'format': '{levelname} {message}',
           'style': '{',
       },
   },
   'handlers': {
       'file': {
           'level': 'DEBUG',
           'class': 'logging.FileHandler',
           'filename': 'debug.log',
           'formatter': 'verbose',
       },
       'console': {
           'level': 'DEBUG',
           'class': 'logging.StreamHandler',
           'formatter': 'simple',
       },
   },
   'loggers': {
       'django': {
           'handlers': ['console'],
           'level': 'INFO',
           'propagate': True,
       },
       'pong': {
           'handlers': ['console', 'file'],
           'level': 'DEBUG',
           'propagate': False,
       },
   },
}
