# ~/.bashrc: executed by bash(1) for non-login shells.
# see /usr/share/doc/bash/examples/startup-files (in the package bash-doc)
# for examples

# If not running interactively, don't do anything
[ -z "$PS1" ] && return

# don't put duplicate lines in the history. See bash(1) for more options
# don't overwrite GNU Midnight Commander's setting of `ignorespace'.
HISTCONTROL=$HISTCONTROL${HISTCONTROL+:}ignoredups
# ... or force ignoredups and ignorespace
HISTCONTROL=ignoreboth

# append to the history file, don't overwrite it
shopt -s histappend

# for setting history length see HISTSIZE and HISTFILESIZE in bash(1)

# check the window size after each command and, if necessary,
# update the values of LINES and COLUMNS.
shopt -s checkwinsize

# make less more friendly for non-text input files, see lesspipe(1)
#[ -x /usr/bin/lesspipe ] && eval "$(SHELL=/bin/sh lesspipe)"

# set variable identifying the chroot you work in (used in the prompt below)
if [ -z "$debian_chroot" ] && [ -r /etc/debian_chroot ]; then
    debian_chroot=$(cat /etc/debian_chroot)
fi

# set a fancy prompt (non-color, unless we know we "want" color)
case "$TERM" in
    xterm-color) color_prompt=yes;;
esac

# uncomment for a colored prompt, if the terminal has the capability; turned
# off by default to not distract the user: the focus in a terminal window
# should be on the output of commands, not on the prompt
#force_color_prompt=yes

if [ -n "$force_color_prompt" ]; then
    if [ -x /usr/bin/tput ] && tput setaf 1 >&/dev/null; then
	# We have color support; assume it's compliant with Ecma-48
	# (ISO/IEC-6429). (Lack of such support is extremely rare, and such
	# a case would tend to support setf rather than setaf.)
	color_prompt=yes
    else
	color_prompt=
    fi
fi

if [ "$color_prompt" = yes ]; then
    PS1='${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ '
else
    PS1='${debian_chroot:+($debian_chroot)}\u@\h:\w\$ '
fi
unset color_prompt force_color_prompt

# If this is an xterm set the title to user@host:dir
case "$TERM" in
xterm*|rxvt*)
    PS1="\[\e]0;${debian_chroot:+($debian_chroot)}\u@\h: \w\a\]$PS1"
    ;;
*)
    ;;
esac

# enable color support of ls and also add handy aliases
if [ -x /usr/bin/dircolors ]; then
    test -r ~/.dircolors && eval "$(dircolors -b ~/.dircolors)" || eval "$(dircolors -b)"
    alias ls='ls --color=auto'
    #alias dir='dir --color=auto'
    #alias vdir='vdir --color=auto'

    #alias grep='grep --color=auto'
    #alias fgrep='fgrep --color=auto'
    #alias egrep='egrep --color=auto'
fi

# some more ls aliases
#alias ll='ls -l'
#alias la='ls -A'
#alias l='ls -CF'

# Alias definitions.
# You may want to put all your additions into a separate file like
# ~/.bash_aliases, instead of adding them here directly.
# See /usr/share/doc/bash-doc/examples in the bash-doc package.

if [ -f ~/.bash_aliases ]; then
    . ~/.bash_aliases
fi

#get __git_ps1 argument from git-prompt.sh
#if [ -f ~/myScript/.git-prompt.sh ]; then
    source ~/myScript/.git-prompt.sh
    export PS1='Geoff[\W]$(__git_ps1 "(%s)"):'
#fi

export GIT_PS1_SHOWDIRTYSTATE=1
export PS1='\[\033[01;37m\]\u@\H\[\033[00;36m\]$(__git_ps1)\[\033[01;34m\]\w\[\033[01;33m\]\$\[\033[00m\]'


# enable programmable completion features (you don't need to enable
# this, if it's already enabled in /etc/bash.bashrc and /etc/profile
# sources /etc/bash.bashrc).
if [ -f /etc/bash_completion ] && ! shopt -oq posix; then
    . /etc/bash_completion
fi

## create a ssh-agent program in the bachground and add ssh key in memory
#eval `ssh-agent`
#ssh-add ~/.ssh/id_rsa
#ssh-add ~/.ssh/id_rsa_git

#Path Abbrivation
#export PROMPT_COMMAND='PS1X=$(perl -pl0 -e "s|^${HOME}|~|;s|([^/])[^/]*/|$""1/|g" <<<${PWD})'


#define Path as constant
export XG='/home/gree/xgree/gundam/'
export FE='/home/gree/xgree/gundam/frontend/gundam/'
export TP='/home/gree/xgree/gundam/frontend/gundam/template/ja_JP/'
export SV='/home/gree/xgree/gundam/Service/Gundam/'
export PS='/home/gree/xgree/gundam/Service/Gundam/Processor/'
export MS='/home/gree/common/pub/lib/src/acm/Masters/'

#define common used directory movements
alias frontend='cd /home/gree/xgree/gundam/frontend/gundam/'
alias action='cd /home/gree/xgree/gundam/frontend/gundam/action/'
alias service='cd /home/gree/xgree/gundam/Service/Gundam/'
alias processor='cd /home/gree/xgree/gundam/Service/Gundam/Processor/'
alias masters='cd /home/gree/common/pub/lib/src/acm/Masters/'
alias xgree='cd /home/gree/xgree/gundam/'
alias gree='cd /home/gree'
alias module='cd /home/gree/xgree/gundam/Service/Gundam/Module/'
alias template='cd /home/gree/xgree/gundam/frontend/gundam/template/ja_JP/'
alias config='cd /home/gree/xgree/gundam/Service/Gundam/Config'

#######################################################################
#define common used commands abbrivation.
alias la='ls -al'
alias cl='clear'
alias sc='screen -A'
alias lsc='screen -ls'
alias dsc='screen -X -S'
alias rsc='screen -R -S -A'
alias remotelast='git log origin/$(git rev-parse --abbrev-ref HEAD) | head -6'
alias taillog='tail -f /var/log/php.log'
alias editlog='vim /var/log/php.log'
alias edittime='vim /home/gree/xgree/gundam/etc/debug/.now'
alias findp='find -name "*.php" |xargs grep --'
alias findc='find -name "*.css" |xargs grep --'
alias findj='find -name "*.js" |xargs grep --'
alias findt='find -name "*.tpl" |xargs grep --'
alias sg='ssh-agent bash'
alias sd='ssh-add ~/.ssh/id_rsa'
alias sdg='ssh-add ~/.ssh/id_rsa_git'
alias cutin='vim /home/gree/xgree/gundam/Service/Gundam/Config/CutinConfig.ini.php '

alias testdb='mysql -ugmasters -pgundam20110901 -h172.17.98.2 gundam_dev'
alias qa4='ssh 172.17.98.229'
alias qa5='ssh 172.17.98.233'
alias qa6='ssh 172.17.98.237'
alias qa7='ssh 172.17.98.203'

alias frontend='cd /home/gree/xgree/gundam/frontend/gundam'
alias action='cd /home/gree/xgree/gundam/frontend/gundam/action'
alias service='cd /home/gree/xgree/gundam/Service/Gundam'
alias processor='cd /home/gree/xgree/gundam/Service/Gundam/Processor'
alias masters='cd /home/gree/common/pub/lib/src/acm/Masters'
alias xgree='cd /home/gree/xgree/gundam/'
alias gree='cd /home/gree'
alias template='cd /home/gree/xgree/gundam/frontend/gundam/template/ja_JP/'
alias findp='find -name "*.php" |xargs grep'
alias testdb='mysql -ugmasters -pgundam20110901 -h172.17.98.2'
alias taillog='tail -f /var/log/php.log'
alias editlog='vim /var/log/php.log'
alias edittime='vim /home/gree/xgree/gundam/etc/debug/.now'
alias findp='find -name "*.php" |xargs grep --'
alias findc='find -name "*.css" |xargs grep --'
alias findj='find -name "*.js" |xargs grep --'
alias findt='find -name "*.tpl" |xargs grep --'
alias sg='ssh-agent bash'
alias sd='ssh-add ~/.ssh/id_rsa'
alias sdg='ssh-add ~/.ssh/id_rsa_git'
alias cutin='vim /home/gree/xgree/gundam/Service/Gundam/Config/CutinConfig.ini.php '

alias testdb='mysql -ugmasters -pgundam20110901 -h172.17.98.2 gundam_dev'
alias qa4='ssh 172.17.98.229'
alias qa5='ssh 172.17.98.233'
alias qa6='ssh 172.17.98.237'
alias qa7='ssh 172.17.98.203'
cd /home/hsu/utility/unitload 
