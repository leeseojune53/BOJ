package com.leeseojune.awss3.service;

import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;
import java.net.MalformedURLException;

public interface ImageService {

    String upload(MultipartFile file) throws IOException;
    String generateObjectUrl(String objectName) throws MalformedURLException;
    byte[] getObject(String fileName) throws IOException;
    void delete(String objectName);

}
