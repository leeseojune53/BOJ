package com.dsm.daily_book.entity.Friend;

import com.dsm.daily_book.entity.user.User;
import com.fasterxml.jackson.annotation.JsonBackReference;
import lombok.*;

import javax.persistence.*;

@Entity
@AllArgsConstructor
@NoArgsConstructor
@Builder
@Getter
@Setter
public class FriendSend {
    @Id @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Integer sendCode;

    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "user_code")
    @JsonBackReference
    private User user;

    private int friendUserCode;

    public FriendSend(User user, int friendUserCode){
        this.user = user;
        this.friendUserCode = friendUserCode;
    }
}
