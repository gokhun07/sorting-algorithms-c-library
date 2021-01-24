import sys

with open('./test_arrays.h', 'w+', encoding='utf-8') as f:
    import random
    from os import linesep as endl

    size_of_rows_in_arr    = 1000 
    size_of_columns_in_arr = 100 
    
    lib = '"stdlib.h"'
    f.write(r"#include" + lib)
    f.write(endl)
    f.write("#define TEST_ARR_ROW_SIZE " + str(size_of_rows_in_arr) )
    f.write(endl)
    f.write("#define TEST_ARR_COLUMN_SIZE " + str(size_of_columns_in_arr) )
    f.write(endl)
    f.write("int32_t test_arr1[][" + str(size_of_columns_in_arr) + "] = {")
    f.write(endl)
    for i in range(size_of_rows_in_arr):
        numberList = []
        f.write("{")
        for j in range(size_of_columns_in_arr):
            num = random.randint(-1000000, 1000000)
            while num in numberList:
                num = random.randint(-1000000, 1000000)

            numberList.append(num)

            if j == size_of_columns_in_arr - 1:
                f.write(str(numberList[j]))

            if j < size_of_columns_in_arr - 1  :
                f.write(str(numberList[j]) + ",")

        f.write("},")
        f.write(endl)

        f.write("{")
        for k in range(size_of_columns_in_arr):
            if k == size_of_columns_in_arr - 1:
                f.write(str(sorted(numberList)[k]))
            if k < size_of_columns_in_arr - 1:
                f.write(str(sorted(numberList)[k]) + ",")
        if i < (size_of_rows_in_arr - 1):
            f.write("},")
            f.write(endl)
        else:
            f.write("}")
            f.write(endl)
    f.write("};")
