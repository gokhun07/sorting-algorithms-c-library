#include <cstdio>
#include <stdint.h> 


bool arrays_are_eq(int32_t * arr1, int32_t* arr2, uint32_t size1, uint32_t size2)
{
    if (size1 != size2)
      {
          return (false);
      }
    
    for (size_t i = 0; i < size1; i++)
    {
        if (*(arr1 + i) != *(arr2 +i))
            return false;
    }
    
 return true;    
}