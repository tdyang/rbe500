from setuptools import setup

package_name = 'scara_fk'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='tracy',
    maintainer_email='tracy@todo.todo',
    description='SCARA forward kinematics node',
    license='TODO',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'fk_node = scara_fk.fk_node:main',
        ],
    },
)