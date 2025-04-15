# Stage 1: Build stage
FROM alpine:latest as builder
RUN apk add --no-cache g++ make curl

# Download source code from GitHub
WORKDIR /app
RUN curl -L -o source.zip https://github.com/GHMaksym/DevOps/archive/refs/heads/branchHTTPserver.zip && \
    unzip source.zip && \
    cd DevOps-branchHTTPserver && \
    make

# Stage 2: Minimal runtime image
FROM alpine:latest
WORKDIR /app
COPY --from=builder /app/DevOps-branchHTTPserver/shxcalc-server /app/shxcalc-server
EXPOSE 8080
ENTRYPOINT ["./shxcalc-server"]
