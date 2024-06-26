//linux (steinum)
{
  "shell_cmd": "g++ -std=c++20 \"${file}\" -o \"${file_path}/${file_base_name}\" && timeout 10s \"${file_path}/${file_base_name}\"<~/Documents/input.txt>~/Documents/output.txt  && rm \"${file_path}/${file_base_name}\"",
  "file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
  "working_dir": "${file_path}",
  "selector": "source.c++",
  "variants":
  [
    {
      "name": "Run",
      "shell_cmd": "\"${file_path}/${file_base_name}\"<~/Documents/input.txt>~/Documents/output.txt"
    },
    {
      "name": "Format Astyle",
      "shell_cmd": "astyle -A2 -T -p \"${file}\" && rm \"${file_path}/${file_name}\".orig"
    },
    {
      "name": "Format Astyle + build + run",
      "shell_cmd": "astyle -A2 -T -p \"${file}\" && rm \"${file_path}/${file_name}\".orig && g++ -std=c++20 \"${file}\" -o \"${file_path}/${file_base_name}\" && timeout 10s \"${file_path}/${file_base_name}\"<~/Documents/input.txt>~/Documents/output.txt && rm \"${file_path}/${file_base_name}\""
    },
    {
      "name": "debug + input output",
      "shell_cmd": "g++ -DLOCAL -std=c++17  -Wshadow -Wall \"$file_name\" -o \"$file_base_name\"  -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g && timeout 10s \"${file_path}/${file_base_name}\"<~/Documents/input.txt>~/Documents/output.txt  && rm \"${file_path}/${file_base_name}\""
    },
    {
      "name": "c++14",
      "shell_cmd": "g++ -std=c++14 \"${file}\" -o \"${file_path}/${file_base_name}\" && timeout 10s \"${file_path}/${file_base_name}\"<~/Documents/input.txt>~/Documents/output.txt  && rm \"${file_path}/${file_base_name}\""
    },
    {
      "name": "opencv",
      "shell_cmd": "echo 'cmake_minimum_required(VERSION 3.25.2)\nproject( \"$file_base_name\" )\nfind_package( OpenCV REQUIRED )\ninclude_directories( \\${OpenCV_INCLUDE_DIRS} )\nadd_executable( main \"$file_name\" )\ntarget_link_libraries( main \\${OpenCV_LIBS} )\n' > CMakeLists.txt && cmake . && make && gnome-terminal -- sh -c '\"${file_path}/main\";echo;echo;  echo Press ENTER to continue; read line'"

    },
  ]
}
//windows
{
"shell_cmd": "g++.exe -std=c++17 \"$file\" -o \"$file_base_name\".exe && \"$file_base_name.exe\"<\"D://c programes/in.txt\">\"D://c programes/out.txt\"",
"shell":true,
"working_dir":"$file_path",
"selector":"source.c, source.cpp, source.c++"
}
//linux
{
"cmd" : ["g++ -std=c++17 \"$file_name\" && timeout 10s ./a.out <~/Code/input.txt | head -n 2000000 | head -c 50000000 >~/Code/output.txt"], 
"selector" : "source.c,source.cpp,source.c++",
"shell": true,
"working_dir" : "$file_path"
}
