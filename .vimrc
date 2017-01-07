set nocompatible  " be iMproved, required
filetype off      " required

" Change <Leader>
let mapleader = ","

set background=dark

set backspace=2   " Backspace deletes like most programs in insert mode
set nobackup
set nowritebackup
set noswapfile    " http://robots.thoughtbot.com/post/18739402579/global-gitignore#comment-458413287
set history=50
set ruler         " show the cursor position all the time
set showcmd       " display incomplete commands
set incsearch     " do incremental searching
set laststatus=2  " Always display the status line
set autowrite     " Automatically :write before running commands
set cursorline    " highlight the current line the cursor is on
set diffopt+=vertical
set hidden
set timeoutlen=500

" Add project file paths
set suffixesadd+=.js
set path+=,,

" Make it obvious where 80 characters is
set textwidth=80
setl sw=4 sts=4 et

" Hidden characters
set list
set listchars=eol:$,tab:>-,trail:~,extends:>,precedes:<

" Numbers
set number
set relativenumber
set numberwidth=5

"sm:    flashes matching brackets or parentheses
set showmatch

" Softtabs, 2 spaces
set tabstop=4
set shiftwidth=4
set shiftround
set expandtab

"sta:   helps with backspacing because of expandtab
set smarttab

" When scrolling off-screen do so 3 lines at a time, not 1
set scrolloff=3

" Enable tab complete for commands.
" first tab shows all matches. next tab starts cycling through the matches
set wildmenu

set spelllang=en_gb

" ABBREVIATIONS
" Add closing html tag
:iabbrev <// </<C-X><C-O>

" Tab completion
" will insert tab at beginning of line,
" will use completion if not at beginning
set wildmode=list:longest,list:full
function! InsertTabWrapper()
  let col = col('.') - 1
  if !col || getline('.')[col - 1] !~ '\k'
    return "\<tab>"
  else
    return "\<c-p>"
  endif
endfunction
inoremap <Tab> <c-r>=InsertTabWrapper()<cr>
inoremap <S-Tab> <c-n>


" Switch syntax highlighting on, when the terminal has colors
" Also switch on highlighting the last used search pattern.
if (&t_Co > 2 || has("gui_running")) && !exists("syntax_on")
  syntax on
endif

filetype plugin indent on

" Set indent based on filetype
au FileType javascript setl sw=4 sts=4 et
au FileType javascript set textwidth=100

augroup vimrcEx
  autocmd!

  " When editing a file, always jump to the last known cursor position.
  " Don't do it for commit messages, when the position is invalid, or when
  " inside an event handler (happens when dropping a file on gvim).
  autocmd BufReadPost *
        \ if &ft != 'gitcommit' && line("'\"") > 0 && line("'\"") <= line("$") |
        \   exe "normal g`\"" |
        \ endif

  autocmd StdinReadPre * let s:std_in=1

  " Set syntax highlighting for specific file types
  autocmd BufRead,BufNewFile *.ejs set filetype=html
  autocmd BufRead,BufNewFile Appraisals set filetype=ruby
  autocmd BufRead,BufNewFile *.md set filetype=markdown

  " Enable spellchecking for Markdown
  autocmd FileType markdown setlocal spell

  " Automatically wrap at 80 characters for Markdown
  autocmd BufRead,BufNewFile *.md setlocal textwidth=80

  " Automatically wrap at 72 characters and spell check git commit messages
  autocmd FileType gitcommit setlocal textwidth=72
  autocmd FileType gitcommit setlocal spell

  " Allow stylesheets to autocomplete hyphenated words
  autocmd FileType css,scss,sass setlocal iskeyword+=-

  " Indent folding with manual folds
  set foldlevel=99
  au BufReadPre * setlocal foldmethod=syntax
  au BufWinEnter * if &fdm == 'indent' | setlocal foldmethod=manual | endif
augroup END

" bind K to grep word under cursor
nnoremap K :grep! "\b<C-R><C-W>\b"<CR>:cw<CR>
" bind F to find word under cursor
nnoremap F /\c<C-R><C-W><CR>
" bind | to find word under cursor
nnoremap FF :%s/<c-r><c-w>/<c-r><c-w>/g<left><left>
" bind T to jump to tag under cursor
nnoremap T :tag <C-R><C-W><CR>

" Open new split panes to right and bottom, which feels more natural
set splitbelow
set splitright

" Run commands that require an interactive shell
nnoremap <Leader>r :RunInInteractiveShell<space>

" Quicker window movement
nnoremap <C-j> <C-w>j
nnoremap <C-k> <C-w>k
nnoremap <C-h> <C-w>h
nnoremap <C-l> <C-w>l

" Buffer navigation
nnoremap <leader>h :bprevious<CR>
nnoremap <leader>l :bnext<CR>
nnoremap <leader>te :tabedit<CR>
nnoremap <leader>bd :Bdelete<CR>

" Toggle folds
inoremap <F9> <C-O>za
nnoremap <F9> za
onoremap <F9> <C-C>za
vnoremap <F9> zf
nnoremap <silent> <Space> @=(foldlevel('.')?'za':"\<Space>")<CR>
vnoremap <Space> zf

" Remap F1 from Help to ESC.  No more accidents.
nmap <F1> <Esc>
map! <F1> <Esc>

" search next/previous -- center in page
nmap n nzz
nmap N Nzz
nmap * *Nzz
nmap # #nzz

" Yank from the cursor to the end of the line, to be consistent with C and D.
"nnoremap Y y$
" Capital Y yanks to clipboard
noremap Y "+y

" Easily spell check
" http://vimcasts.org/episodes/spell-checking/
nmap <silent> <leader>z :set spell!<CR>

map <C-c>n :cnext<CR>
map <C-c>p :cprevious<CR>

" Switch into background mode
nnoremap <leader>. <C-z>

" inoremap <C-o> my<Esc>o<Esc>`yi
" Git shortcut
map <leader>g :Git<space>

" Move between splits
nnoremap <S-Tab> <C-W>W
nnoremap <Tab> <C-W><C-W>

" No highlight after a search
nnoremap <leader><space> :noh<cr>

" Create split, close split
nnoremap <leader>w <C-w>v<C-w>1
nnoremap <leader>q <C-w>q

" FolderNavigation
nnoremap <C-n> :Explore ~/workspace/<CR>
let g:netrw_liststyle=3

" JK escape
inoremap jk <ESC>

:au FocusLost * :wa

"save and run last command
nnoremap mm :wa<CR>:!!<CR>

"open vimrc
nnoremap <leader>ev <C-w><C-v><C-l>:e ~/workspace/.vimrc<cr>

" source vimrc
nnoremap <leader>es :so ~/workspace/.vimrc<CR>

"make ctrl-c work with vim on a mac
vnoremap <C-c> :w !pbcopy<CR><CR> noremap <C-v> :r !pbpaste<CR><CR>

autocmd FileType javascript inoremap (; ();<Esc>hi
set autowrite

" remove trailing whitespaces on saving
autocmd BufWritePre * :%s/\s\+$//e

" such very magic
:nnoremap / /\c
:cnoremap %s/ %s/\v

" Indentation
nnoremap <Leader>i gg=G``
nnoremap == gg=G``

nnoremap <leader>q <C-w>q
map zx :wqa<CR>

" Toggle paste mode
nnoremap <leader>p :set invpaste paste?<CR>
imap <leader>p <C-O>:set invpaste paste?<CR>
set pastetoggle=<leader>p

" Move up and down by visual line
nnoremap j gj
nnoremap k gk

" Add empty line in normal mode
nmap <C-j> O<Esc>j
nmap <C-k> o<Esc>k

" Hard times
let g:hardtime_default_on = 1
