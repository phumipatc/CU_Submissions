"""
    Task	: 08_Dict_24_Texting
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 15 September 2021 [22:27]
    Algo	: 
    Status	: 
"""
mapping = {'a': '2',
           'b': '22',
           'c': '222',
           'd': '3',
           'e': '33',
           'f': '333',
           'g': '4',
           'h': '44',
           'i': '444',
           'j': '5',
           'k': '55',
           'l': '555',
           'm': '6',
           'n': '66',
           'o': '666',
           'p': '7',
           'q': '77',
           'r': '777',
           's': '7777',
           't': '8',
           'u': '88',
           'v': '888',
           'w': '9',
           'x': '99',
           'y': '999',
           'z': '9999',
           ' ': '0'
           }
reverse_mapping = {y: x for x, y in mapping.items()}


def text2keys(text):
    return ' '.join([mapping[x.lower()] for x in text if x.lower() in mapping])


def keys2text(keys):
    return ''.join([reverse_mapping[x] for x in keys.split()])


exec(input().strip())
