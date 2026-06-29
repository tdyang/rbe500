from setuptools import find_packages
from setuptools import setup

setup(
    name='scara_ik',
    version='0.0.0',
    packages=find_packages(
        include=('scara_ik', 'scara_ik.*')),
)
