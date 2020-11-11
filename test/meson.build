gtest_srcs= files(['gtest_main.cpp', 'resultKeeperTest.cpp'])


gtest_dep = gtest_sp.get_variable('gtest_dep')
gmock_dep = gtest_sp.get_variable('gmock_dep')

gtest_exec = executable('TennisResultTdd', gtest_srcs, 
  dependencies :[gtest_dep, gmock_dep, project_dep])

test('Tennis result TDD', gtest_exec)
