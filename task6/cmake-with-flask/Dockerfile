FROM ubuntu
ADD . .
WORKDIR .
ENV TZ=Europe/Minsk
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime 
RUN echo $TZ > /etc/timezone
RUN echo alkdf
RUN apt update; apt install -y g++ cmake make python3.8 python3-pip
RUN python3.8 -m pip install flask
RUN useradd techproguser
RUN mkdir build
RUN cd build
RUN cmake ..
RUN make
RUN cd ..
RUN ./bin/C
# RUN cp -r /bin/C ../
CMD ["python3.8", "app.py", "--port", "5000", "--host", "0.0.0.0"]
# RUN python app.py
# CMD ["ls"]
# CMD ["mkdir", "build"]
# CMD ["cd", "build"]
# CMD ["cmake", ".."]

