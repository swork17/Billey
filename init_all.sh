PORT="$1"
make fclean
make
xterm -title "Client 1" -hold -e "./bin/Client "$PORT" 1" &
xterm -title "Client 2" -hold -e "./bin/Client "$PORT" 2" &
xterm -title "Client 3" -hold -e "./bin/Client "$PORT" 3" &
xterm -title "Client 4" -hold -e "./bin/Client "$PORT" 4" &