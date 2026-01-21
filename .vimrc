call plug#begin('~/.vim/plugged')

Plug 'catppuccin/vim'

call plug#end()

set termguicolors
colorscheme catppuccin_mocha

set number
syntax enable
set tabstop=4
set nocopyindent
filetype indent off
