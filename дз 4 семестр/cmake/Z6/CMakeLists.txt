function(print var_name)
    message("${var_name} = \"${${var_name}}\"")
endfunction()

# Пример использования:
set(VAR "Cats and Dogs")
print(VAR)