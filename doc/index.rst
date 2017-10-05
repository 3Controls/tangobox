.. TangoBox - a Tango Controls demo VM documentation master file, created by
   sphinx-quickstart on Thu Oct  5 11:05:36 2017.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to TangoBox - a Tango Controls demo VM's documentation!
===============================================================

TangoBox is a VM image running Tango Controls system and its various tools.
It is intended to be used for demonstration and training.
It also simulates distributed deployment by using Docker.



.. toctree::
   :maxdepth: 2
   :caption: Contents:

What is installed
=================

Below there is list of provide packages/features. Please note that some of them
are installed as docker container and maybe switched off (stopped) and requires to be switched
on for being explored, see :ref:`Switching containers on and off <container_switch_on_off>`

* Tango 9.2.5
* PyTango 9.2.2
* Taurus 4.2.2
* QTango
* Linac system simulation (as docker container tangobox-sim)
* HDB/TDB (as docker container tangobox-archiving)
* HDB++ (as docker container tangobox-hdbpp)
* SerialLine, Modbus and PyPLC device server (as docker container tangobox-com)
* mTango (as docker container tangobox-web)


First steps
===========


After importing the VM image to VirtualBox you may start it.

* Username is: `tango-cs`
* Password is: `tango`

`tango-cs` user has sudo rights, so he may invoke commands as superuser with command :command:`sudo`.

You may explore the Tango Controls feature by clicking related shortcuts on the Desktop.

.. note::

   Plese note that some shortcuts are related to features running on containers. Please start related container first.
   See the following section.


.. _container_switch_on_off:

Switching containers on and off
===============================

Some of the features of Tango are provided inside pre-build docker containers.
These can be switched on and off by starting or stopping related containers.
Containers behave similar to virtual machines with they own network cards and operating system stack,
however, lacking full separations.

To start a container, open terminal and invoke :command:`docker start {container-name}`. For example, to star
a linac simulation use the following statement:

.. code-block:: bash

   docker start tangobox-sim


To stop a container, open terminal and invoke :command:`docker stop {container-name}`. For example, to stop
a linac simulation use the following statement:

.. code-block:: bash

   docker stop tangobox-sim

To see which containers are running please, call :command:`docker ps`


Deployment structure
====================

Network
-------

Containers are created withing their own subnet: `172.18.0.0/16`. The network is called `tango_nw`
The subnet was created with the following docker command:

.. code-block:: bash

   docker network create --driver=bridge --subnet=172.18.0.0/16 --opt com.docker.network.bridge.enable_icc=true \
   --opt com.docker.network.bridge.host_binding_ipv4="0.0.0.0" --opt com.docker.network.bridge.mtu=1500 \
   --opt com.docker.network.bridge.enable_ip_masquerade=true  tango_nw

Containers are assigned static IPs. List of the IPs assignment maybe seen in :file:`/etc/hosts`. Use command
:command:`cat /etc/hosts` to see its contents.

Containers and images dependency
--------------------------------

Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`
