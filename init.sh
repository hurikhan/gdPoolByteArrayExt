#! /usr/bin/env bash

GODOT_BIN="godot"

if [ ! $0 == "./init.sh" ]; then
	echo "init.sh has to be executed in the directory directly."
	exit 1
fi

function print_help {
	echo "Usage: $0 [component]"
	echo ''
	echo '[component]'
	echo '	sub [provider]	--	initilizes and updates the git submodules'
	echo ''
	echo '[provider]'
	echo '	github.com	--	Sets the .gitmodules entries to github.com. <default>'
	echo '	gitee.com	--	Sets the .gitmodules entries to gitee.com.'
}

function init_sub {
	grep '^\[submodule' .git/config > /dev/null
	if [ $? == 0 ]; then
		echo "Git submodules already initialized! Aborting!"
		exit 2
	fi

	if [ ! -z $1 ]; then
		case $1 in
			github.com)
				;;
			*)
				echo "Unknow provider! Aborting!"
				echo 
				print_help
				exit 3
		esac
	fi

	git submodule update --init --recursive
}

function init_api {
	#./$GODOT_BIN --gdnative-generate-json-api api.json
	cd src/godot-cpp
	#scons platform=linux generate_bindings=yes use_custom_api_file=yes custom_api_file=../../api.json
	scons platform=linux generate_bindings=yes bits=64
	cd ../..
}

case $1 in
	sub)
		if [ -z $2 ]; then
			init_sub
		else
			init_sub $2
		fi
		;;

	api)
		init_api
		;;	
	*)
		print_help
		;;
esac
