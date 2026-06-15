" Improved
set nocompatible

" Color
call plug#begin('~/.vim/plugged')
Plug 'catppuccin/vim'
call plug#end()
set termguicolors
colorscheme catppuccin_mocha

" Basic 
syntax on
set nowrap
set tabstop=4
set nosmarttab
set nocopyindent
set relativenumber
filetype plugin on
set backspace=indent,eol,start

" Cursors
let &t_SI = "\e[6 q"
let &t_EI = "\e[2 q" 
let &t_SR = "\e[4 q"
