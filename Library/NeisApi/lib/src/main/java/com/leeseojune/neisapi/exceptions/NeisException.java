package com.leeseojune.neisapi.exceptions;

import org.apache.http.HttpException;

public class NeisException extends HttpException {

    public NeisException() {
        super();
    }

    public NeisException(String message) {
        super(message);
    }

    public NeisException(String message, Throwable cause) {
        super(message, cause);
    }

}
