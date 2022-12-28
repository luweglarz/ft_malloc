FROM debian:buster

RUN apt-get update \
&& apt -y install build-essential \
&& apt-get install -y locales 

RUN mkdir ft_malloc

CMD tail -f /dev/null