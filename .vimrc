"******************************************************
"bundle配置
"******************************************************
set nocompatible
filetype off
"set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

Bundle 'gmarik/vundle'

Bundle 'majutsushi/tagbar'
"nmap <Leader> tb :TagbarToggle<CR>
map <F3> :Tagbar<CR>

Bundle 'scrooloose/nerdtree'
map <F2> :NERDTreeToggle<CR>

Bundle 'fholgado/minibufexpl.vim'
let g:miniBufExplMapWindowNavVim=1
let g:miniBufExplMapWindowNavArrows=1
let g:miniBufExplMapCTabSwitchBufs=1
let g:miniBufExplModSelTarget=1
let g:miniBufExplMoreThanOne=0
map <F11> :MBEbp<CR>
map <F12> :MBEbn<CR>

Bundle 'bling/vim-airline'
set laststatus=2

Bundle 'vim-scripts/winmanager'
"let g:NERDTree_title="[NERDTree]"
"let g:winManagerWindowLayout="NERDTree|BufExplorer"
"function! NERDTree_start()
"	exec 'NERDTree'
"endfunction
"function! NERDTree_IsValid()
"	return 1
"endfunction
let g:winManagerWindowLayout='FileExplorer|TagList'
nmap wm :WMToggle<CR>

Bundle 'taglist.vim'
let Tlist_Ctags_Cmd='ctags'
let Tlist_Show_One_Files=1
let Tlist_WinWidt=28
let Tlist_Exit_OnlyWindow=1
let Tlist_Use_Left_Windo=1

"Bundle 'Valloric/YouCompleteMe'

Bundle 'scrooloose/nerdcommenter'
let mapleader=","
"，cc注释当前行
"，c<space>取消掉注释
"，cm注释块

call vundle#end()
filetype plugin indent on
"******************************************************
"bundle配置
"******************************************************


if(has("win32") || has("win95") || has("win64") || has("win16"))
	let g:iswindows=1
else
	let g:iswindows=0
endif
set nocompatible "不要VIM模仿VI模式
if has("autocmd")
	filetype plugin indent on "根据文件进行缩进
	augroup vimrcEx
		au!
		autocmd FileType text setlocal textwidth=78
		autocmd BufReadPost *
					\ if line("'\"") > 1 && line("'\"") <= line("$") |
					\ exe "normal! g'\"" |
					\ endif
	augroup END
else
	"智能缩进
	set autoindent "always set autoindenting on
endif " has("autocmd")
set tabstop=4 "让一个tab等于4个空格
set vb t_vb=
set hlsearch "高亮显示搜索结果
set incsearch "实时匹配
set backspace=indent,eol,start whichwrap+=<,>,[,] "退格键使用

"检测文件类型 插入文件类型插件 插入特定的文件类型插件
filetype on
filetype plugin on
filetype indent on

syntax enable
syntax on "语法高亮
set nu

set autoindent "自动对齐
set smartindent "智能选择对其方式

"设置tab键为4个空格 行之间交错是使用4个空格
set tabstop=4
set shiftwidth=4

"设置括号匹配模式
set showmatch

"显示光标位置的状态行
set ruler

set novisualbell

set nobackup
set noswapfile

"colorscheme solarized 
"set background=dark

"自带的自动补全
"<ctrl+x> + <tab>
autocmd FileType python set omnifunc=pythoncomplete#Complete
