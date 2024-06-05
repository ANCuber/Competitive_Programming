se nu ru cul cin ai aw is ts=4 sw=4 | syn on
ino jk <Esc>



map <F5> <Esc>:w<Cr>:!g++ -Wall -Wextra -Wshadow -fsanitize=undefine,address %:r.cpp -o %:r && ./%:r && echo "compiled"<Cr>
inoremap <F5> <Esc><F5>
