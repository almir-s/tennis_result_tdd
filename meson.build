project('tennis_result_tdd', 'cpp', default_options:['cpp_std=c++14'])

source_dir = files([])

thread_dep = dependency('threads')

include_dir = include_directories('include')

project_dep = declare_dependency(include_directories: include_dir, sources: source_dir, dependencies: [thread_dep])

gtest_sp = subproject('gtest')
subdir('test')

executable('main', sources: ['src/main.cpp'], dependencies: [project_dep])
