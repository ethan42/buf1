FROM ubuntu:22.04 as builder

RUN apt update && apt install -fy gcc gcc-multilib

COPY overflowme.c overflowme.c

RUN gcc -m32 -static -o overflowme overflowme.c -fno-stack-protector -no-pie -zexecstack

FROM ubuntu:22.04

COPY --from=builder /overflowme* /

CMD ["/overflowme"]
