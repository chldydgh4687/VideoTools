#!/bin/sh

sudo apt-get update
sudo apt-get install ssh
sudo ufw allow 22/tcp
sudo service ssh start
