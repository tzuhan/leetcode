set runtimepath+=~/.vim_runtime

source ~/.vim_runtime/vimrcs/basic.vim
source ~/.vim_runtime/vimrcs/filetypes.vim
source ~/.vim_runtime/vimrcs/plugins_config.vim
source ~/.vim_runtime/vimrcs/extended.vim

try
source ~/.vim_runtime/my_configs.vim
catch
endtry

augroup Cpp
    au BufNewFile *.cpp 0r ~/.vim_runtime/skeleton.cpp
augroup end

augroup Html
    au BufNewFile *.cpp 0r ~/.vim_runtime/skeleton.html
augroup end
