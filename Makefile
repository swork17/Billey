CLIENT_DIR = src/client/
SERVER_DIR = src/server/
BIN_DIR = bin/

.PHONY: project_code

all:
	$(MAKE) -C $(CLIENT_DIR)
	$(MAKE) -C $(SERVER_DIR)

clean:
	$(MAKE) -C $(CLIENT_DIR) clean
	$(MAKE) -C $(SERVER_DIR) clean

fclean: 
	$(MAKE) -C $(CLIENT_DIR) fclean
	$(MAKE) -C $(SERVER_DIR) fclean