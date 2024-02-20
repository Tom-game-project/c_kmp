"""
# use ft_kmp_strstr.c from python

run

```bash
make lib
```

and then run

```python
python main.py
```

"""

import ctypes

class C_ft:

    def __init__(self,dll_path:str):
        self.lib = ctypes.CDLL(dll_path)
        
        # set return type
        self.lib.ft_strlen.restype = ctypes.c_uint32
        self.lib.ft_kmp_strstr.restype = ctypes.c_char_p
        # self.lib.create_skip_list.restype = ctypes.c_int32

    def strlen(self,text:str) -> int:
        ascii_text = ctypes.c_char_p(text.encode("ASCII"))
        
        return self.lib.ft_strlen(ascii_text)

    def strstr(self,text:str, target:str) -> str:
        # setting args
        ascii_text = ctypes.c_char_p(text.encode("ASCII"))
        ascii_target = ctypes.c_char_p(target.encode("ASCII"))

        return self.lib.ft_kmp_strstr(ascii_text, ascii_target).decode("ASCII")
    
    def skipmap(self,text:str) -> list[int]:
        pass

if __name__ == "__main__":
    ft = C_ft("./pkg/ft_kmp_strstr.so")
    
    text="abababbabcabbaaaaaa"
    target="abcabba"
    result = ft.strstr(text,target)
    print("match",result)
    text="helloworld"
    result = ft.strlen(text)
    print("length",result)
