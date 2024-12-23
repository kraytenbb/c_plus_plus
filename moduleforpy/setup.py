from setuptools import setup, Extension

module = Extension('distinct_module', sources=['Source1.cpp'])

setup(
    name='distinct_module',
    version='1.0',
    description='Module to find distinct elements in a list',
    ext_modules=[module],
)
