from setuptools import setup
package_name = 'scara_ik_node'
setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='tracy',
    maintainer_email='tracy@todo.todo',
    description='SCARA IK node',
    license='TODO',
    entry_points={
        'console_scripts': [
            'ik_node = scara_ik_node.ik_node:main',
        ],
    },
)
