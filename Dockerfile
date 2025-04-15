FROM ubuntu:22.04

RUN apt-get update && \
    apt-get install -y g++ make automake autoconf libtool && \
    apt-get clean

WORKDIR /app
COPY . /app

RUN autoreconf --install
RUN ./configure
RUN make

EXPOSE 8080

CMD ["./http_server"]
