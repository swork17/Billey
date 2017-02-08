make fclean
make
xterm -title "Client 1" -hold -e "./bin/Client 8888 1" &
xterm -title "Client 2" -hold -e "./bin/Client 8888 2" &
xterm -title "Client 3" -hold -e "./bin/Client 8888 3" &
xterm -title "Client 4" -hold -e "./bin/Client 8888 4" &