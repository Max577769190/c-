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
"关闭单个文件的taglist按d
"寻找定义的tag按o
let Tlist_Ctags_Cmd='ctags'
let Tlist_Show_One_Files=1
let Tlist_WinWidt=28
let Tlist_Exit_OnlyWindow=1
let Tlist_Use_Left_Windo=1

Bundle 'Valloric/YouCompleteMe'

Bundle 'scrooloose/nerdcommenter'
let mapleader=","
"，cc注释当前行
"，c<space>取消掉注释
"，cm注释块

Bundle 'scrooloose/syntastic'
let g:syntastic_stl_format='[%E{Err: %fe #%e}%B{, }%w{Warn: %fw #%w}]'
set statusline+=%#warningmsg#
set statusline+=%{StntasticStatuslineFlag()}
set statusline+=%*

let g:syntastic_always_populate_loc_list=1
"自动打开location list
let g:syntastic_auto_loc_list=1
let g:syntastic_auto_loc_height=5
let g:syntastic_check_on_open=1
let g:syntastic_check_on_wp=0

let g:syntastic_cpp_comiler='g++'
let g:syntastic_cpp_comiler_options='-std=c++11 -Wall'
let g:syntastic_cpp_config_file='.syntastic_cpp_config'


Bundle 'jiangmiao/auto-pairs'
"括号自动补全

Bundle 'altercation/vim-colors-solarized'

call vundle#end()
filetype plugin indent on
"******************************************************
"bundle配置end
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
filetype plugin indent on

"全能补全 不会用
"set completeopt=longest,menu

set autochdir "自动设置当前编辑的目录为工作目录
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

"启用256色
"set t_Co=256


"找到c.vim cpp.vim
syn match cFunction "\<[a-zA-Z_][a-zA-Z_0-9]*\>[^()]*)("me=e-2
syn match cFunction "\<[a-zA-Z_][a-zA-Z_0-9]*\>s*("me=e-2

"""""""""""""""""""""""""""""
"关于gvim的一些配置
"“‘”“”“”“”“”“”“”“”“”“”’“”“”“”
if has("gui_running")
	let g:isGUI = 1
else
	let g:isGUI = 0
endif

if (g:isGUI)
	"去掉边框
	set go = 

	"设置字体以及行间距
	set guifont=DejaVu\ Sans\ Mono\ 11
	set guifontwide=FZXingKai\-S04\ 12

	"高亮显示当前行与列
	set cursorline
	set cursorcolumn

	"配色方案设置
	colorscheme solarized
	"colorscheme desert
	set background=dark

	"全屏
	function! ToggleFullScreen()
		call system("wmctrl -r :ACTIVE: -b toggle,fullscreen")
	endfunction
	map <silent><F11> :call ToggleFullScreen()<CR>
endif
"""""""""""""""""""""""""""""""""""""""""""""'""""""'"""""""""""""
""编译c++文件
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set makeprg=g++\ -g\ %

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""''""
" =========== NERDTree 和 Tagbar 共用一个窗口 ========  
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
  
function! ToggleNERDTreeAndTagbar()   
let w:jumpbacktohere = 1  
  
" Detect which plugins are open  
if exists('t:NERDTreeBufName')  
    let nerdtree_open = bufwinnr(t:NERDTreeBufName) != -1  
else  
    let nerdtree_open = 0  
endif  
let tagbar_open = bufwinnr('__Tagbar__') != -1  
  
" Perform the appropriate action  
if nerdtree_open && tagbar_open  
    NERDTreeClose  
    TagbarClose  
elseif nerdtree_open  
    TagbarOpen  
    wincmd J  
    wincmd k  
    wincmd L  
elseif tagbar_open  
    NERDTree  
    wincmd J  
    wincmd k  
    wincmd L  
else  
    NERDTree  
    TagbarOpen  
    wincmd J  
    wincmd k  
    wincmd L  
endif  
  
" 改变窗口宽度  
vertical resize +50   
  
" Jump back to the original window  
" for window in range(1, winnr('$'))  
"     execute window . 'wincmd w'  
"     if exists('w:jumpbacktohere')  
"        unlet w:jumpbacktohere  
"        break  
"    endif  
"endfor    
  
endfunction  
  
" nnoremap <leader>\ :call ToggleNERDTreeAndTagbar()<CR>  
   
" 打开 vim 时自动打开 NERDTree 和 Tagbar  
"autocmd vimenter * call ToggleNERDTreeAndTagbar()  
  
" ===================================================  
