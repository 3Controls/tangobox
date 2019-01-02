#!/usr/bin/env bash

# create network
docker network create --driver=bridge --subnet=172.18.0.0/16 --opt com.docker.network.bridge.enable_icc=true --opt com.docker.network.bridge.host_binding_ipv4="0.0.0.0" --opt com.docker.network.bridge.mtu=1500 --opt com.docker.network.bridge.enable_ip_masquerade=true  tango_nw

# images build
cd ../docker
docker image build -t base base/
docker build -t archive archive/
docker build -t sim sim/
docker build -t com com/
docker build -t egiga egiga/
docker build -t hdbpp hdbpp/
docker build -t web web/ 

# containers strart
create-tangobox-container archive
create-tangobox-container sim
create-tangobox-container com
create-tangobox-container egiga
create-tangobox-container hdbpp
create-tangobox-container web

