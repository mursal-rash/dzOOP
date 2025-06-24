function(bubble_sort list_var)
    set(lst "${${list_var}}")
    list(LENGTH lst len)
    
    if(len LESS 2)
        set(${list_var} "${lst}" PARENT_SCOPE)
        return()
    endif()
    
    math(EXPR last_index "${len} - 2")
    
    foreach(i RANGE 0 ${last_index})
        foreach(j RANGE 0 ${last_index})
            if(i EQUAL j)
                continue()
            endif()
            
            list(GET lst ${i} val1)
            list(GET lst ${j} val2)
            
            if("${val1}" STRGREATER "${val2}")
                list(REMOVE_AT lst ${i})
                list(INSERT lst ${i} "${val2}")
                list(REMOVE_AT lst ${j})
                list(INSERT lst ${j} "${val1}")
            endif()
        endforeach()
    endforeach()
    
    set(${list_var} "${lst}" PARENT_SCOPE)
endfunction()

# Пример использования:
set(my_list "Dog;Cat;Mouse;Elephant")
bubble_sort(my_list)
message("Sorted list: ${my_list}")