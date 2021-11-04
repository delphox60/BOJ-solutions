st = input()
result = 0
c_list = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']

for i in c_list:
    while i in st:
        st = st.replace(i, '#', 1)
        result += 1
st = st.replace('#', '')
result += len(st)
print(result)
