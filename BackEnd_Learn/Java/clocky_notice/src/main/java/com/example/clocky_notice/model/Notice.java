package com.example.clocky_notice.model;

import lombok.NoArgsConstructor;
import org.hibernate.annotations.CreationTimestamp;

import javax.persistence.*;
import java.util.Date;

@Entity
@NoArgsConstructor
@Table(name = "test")
public class Notice {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    private String title;
    private String written;
    @CreationTimestamp
    private Date create_time;
    public Notice(String title, String written){
        this.title = title;
        this.written = written;
    }
}
